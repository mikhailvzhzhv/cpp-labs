#pragma once
#include <memory> 
#include <algorithm>

namespace flatmap {

    template <class Key, class Value>
    struct flatmap_st {
        Key first;
        Value second;
    };

    template <class Key,
          class Value,
          class Compare = std::less<Key>,
          class Allocator = std::allocator<flatmap_st<Key, Value>>
        >
    class FlatMap {
    private:
        Allocator a_;
        std::allocator_traits<Allocator> alloc_;
        using map_st = typename std::allocator_traits<Allocator>::value_type;
        using size_type = std::size_t;

        const size_type sizeDef_ = 2;
        size_type sizeMax_;
        size_type sizeCur_;
        map_st* flatmapArr_;

        //возвращает индекс массива структур, по которому лежит key, либо size()
        size_type binary_search(const Key& key) const;

        void swapper(FlatMap& this_map, FlatMap& other_map);

    public:
        // стандартный конструктор
        FlatMap() : sizeMax_(4), sizeCur_(0), flatmapArr_(alloc_.allocate(a_, sizeMax_)) {}

        // конструктор копирования
        FlatMap(const FlatMap& other_map);

        // деструктор
        ~FlatMap() {
            alloc_.deallocate(a_, flatmapArr_, sizeMax_);
        }

        // конструктор перемещения
        FlatMap(FlatMap&& x) noexcept;
        
        // оператор присваивания с перемещением
        FlatMap& operator=(FlatMap&& x) noexcept;

        // оператор присваивания 
        FlatMap& operator=(const FlatMap& other_map);

        // получить количество элементов в таблице
        std::size_t size() const;

        // доступ / вставка элемента по ключу
        Value& operator[](const Key& key);

        // возвращает true, если запись с таким ключом присутствует в таблице
        bool contains(const Key& key) const;

        // удаление элемента по ключу, возвращает количество удаленных элементов (0 или 1)
        std::size_t erase(const Key& key);

        // очистка таблицы, после которой size() возвращает 0, а contains() - false на любой ключ
        void clear();


        class Iterator {
        private:
            map_st* iter;

        public:
            Iterator(map_st* it) {
                iter = it;
            }

            map_st& operator*() const {
                return *iter;
            }

            map_st* operator->() const {
                return iter;
            }

            Iterator& operator++() {
                ++iter;
                return *this;
            }

            bool operator==(const Iterator& other) const {
                return iter == other.iter;
            }

            bool operator!=(const Iterator& other) const {
                return iter != other.iter;
            }
        };

        // Получить итератор на первый элемент
        Iterator begin() const;

        // Получить итератор на элемент, следующий за последним
        Iterator end() const;

        // Получить итератор на элемент по данному ключу, или на end(), если такого ключа нет
        Iterator find(const Key& x) const;
    };


    //возвращает индекс массива структур, по которому лежит key, либо size()
    template <class Key,
          class Value,
          class Compare,
          class Allocator
         >
    typename FlatMap<Key, Value, Compare, Allocator>::size_type 
    FlatMap<Key, Value, Compare, Allocator>::binary_search(const Key& key) const {
        size_type min = 0;
        size_type max = sizeCur_;
        size_type keyIdx = 0;
        bool found = false;

        while (!found && min != max) {
            keyIdx = min + (max - min) / 2;
            if (Compare{}(key, flatmapArr_[keyIdx].first)) {
                max = keyIdx;
            }
            else if (Compare{}(flatmapArr_[keyIdx].first, key)) {
                min = keyIdx + 1;
            }
            else {
                found = true;
            }
        }

        return found ? keyIdx : sizeCur_;
    }

    // конструктор копирования
    template <class Key,
          class Value,
          class Compare,
          class Allocator
         >
    FlatMap<Key, Value, Compare, Allocator>::FlatMap(const FlatMap& other_map) : 
        sizeMax_(other_map.sizeMax_), 
        sizeCur_(other_map.sizeCur_),
        flatmapArr_(alloc_.allocate(a_ , sizeMax_)) {

        std::uninitialized_copy(other_map.flatmapArr_, other_map.flatmapArr_ + other_map.size(), flatmapArr_);
    }

    // конструктор перемещения
    template <class Key,
          class Value,
          class Compare,
          class Allocator
         >
    FlatMap<Key, Value, Compare, Allocator>::FlatMap(FlatMap&& x) noexcept
    :   sizeMax_(x.sizeMax_)
    ,   sizeCur_(x.sizeCur_) 
    ,   flatmapArr_(x.flatmapArr_) {

        x.flatmapArr_ = nullptr;
        x.sizeCur_ = 0;
        x.sizeMax_ = 0;
    }

    // оператор присваивания
    template <class Key,
          class Value,
          class Compare,
          class Allocator
         >
    FlatMap<Key, Value, Compare, Allocator>& FlatMap<Key, Value, Compare, Allocator>::operator=(const FlatMap& other_map) {
        if (&other_map == this) {
            return *this;
        }

        FlatMap<Key, Value, Compare, Allocator> tmp(other_map);
        swapper(*this, tmp);

        return *this;
    }

    // оператор присваивания с перемещением
    template <class Key,
          class Value,
          class Compare,
          class Allocator
         >
    FlatMap<Key, Value, Compare, Allocator>& FlatMap<Key, Value, Compare, Allocator>::operator=(FlatMap&& x) noexcept {
        if (this != &x) {
            a_ = std::move(x.a_);
            alloc_ = std::move(x.alloc_);
            sizeMax_ = x.sizeMax_;
            sizeCur_ = x.sizeCur_;
            flatmapArr_ = x.flatmapArr_;
            x.flatmapArr_ = nullptr;
        }
        return *this;
    }

    // получить количество элементов в таблице
    template <class Key,
          class Value,
          class Compare,
          class Allocator
         >
    std::size_t FlatMap<Key, Value, Compare, Allocator>::size() const {
        return sizeCur_;
    }

    // доступ / вставка элемента по ключу
    template <class Key,
          class Value,
          class Compare,
          class Allocator
         >
    Value& FlatMap<Key, Value, Compare, Allocator>::operator[](const Key& key) {
        auto keyIdx = binary_search(key);

        if (keyIdx == sizeCur_) {
            if (sizeCur_ == sizeMax_) {
                sizeMax_ *= 2;
                FlatMap<Key, Value, Compare, Allocator> tmp(*this);
                swapper(*this, tmp); 
            }

            Value tmp;
            const auto pair = map_st{key, tmp};
            flatmapArr_[sizeCur_].first = pair.first;
            keyIdx = sizeCur_;

            for (auto i = sizeCur_; i > 0 && Compare{}(key, flatmapArr_[i - 1].first); --i) {
                flatmapArr_[i] = flatmapArr_[i - 1];
                flatmapArr_[i - 1] = pair;

                keyIdx = i - 1;
            }

            ++sizeCur_;
        }

        return flatmapArr_[keyIdx].second;
    }

    // возвращает true, если запись с таким ключом присутствует в таблице
    template <class Key,
          class Value,
          class Compare,
          class Allocator
         >
    bool FlatMap<Key, Value, Compare, Allocator>::contains(const Key& key) const {
        return binary_search(key) != sizeCur_;
    }

    // удаление элемента по ключу, возвращает количество удаленных элементов (0 или 1)
    template <class Key,
          class Value,
          class Compare,
          class Allocator
         >
    std::size_t FlatMap<Key, Value, Compare, Allocator>::erase(const Key& key) {
        std::size_t keyIdx = binary_search(key);
        if (keyIdx == sizeCur_) {
            return 0;
        }
        for (std::size_t i = keyIdx; i < sizeCur_ - 1; ++i) {
            flatmapArr_[i] = flatmapArr_[i + 1];
        }
        --sizeCur_;

        return 1;
    }

    // очистка таблицы, после которой size() возвращает 0, а contains() - false на любой ключ
    template <class Key,
          class Value,
          class Compare,
          class Allocator
         >
    void FlatMap<Key, Value, Compare, Allocator>::clear() {
        sizeCur_ = 0;
        sizeMax_ = sizeDef_;

        FlatMap<Key, Value, Compare, Allocator> tmp(*this);
        swapper(*this, tmp);
    }

    // Получить итератор на первый элемент
    template <class Key,
          class Value,
          class Compare,
          class Allocator
         >
    typename FlatMap<Key, Value, Compare, Allocator>::Iterator FlatMap<Key, Value, Compare, Allocator>::begin() const {
        return FlatMap::Iterator(flatmapArr_);
    }

    // Получить итератор на элемент, следующий за последним
    template <class Key,
          class Value,
          class Compare,
          class Allocator
         >
    typename FlatMap<Key, Value, Compare, Allocator>::Iterator FlatMap<Key, Value, Compare, Allocator>::end() const {
        return FlatMap::Iterator(flatmapArr_ + sizeCur_);
    }

    // Получить итератор на элемент по данному ключу, или на end(), если такого ключа нет
    template <class Key,
          class Value,
          class Compare,
          class Allocator
         >
    typename FlatMap<Key, Value, Compare, Allocator>::Iterator FlatMap<Key, Value, Compare, Allocator>::find(const Key& x) const {
        return flatmapArr_ + binary_search(x);
    }

    template <class Key,
          class Value,
          class Compare,
          class Allocator
         >
    void FlatMap<Key, Value, Compare, Allocator>::swapper(FlatMap& this_map, FlatMap& other_map) {
        std::swap(this_map.alloc_, other_map.alloc_);
        std::swap(this_map.flatmapArr_, other_map.flatmapArr_);
        std::swap(this_map.sizeCur_, other_map.sizeCur_);
        std::swap(this_map.sizeMax_, other_map.sizeMax_);
    }

}