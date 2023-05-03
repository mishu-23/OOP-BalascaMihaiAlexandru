#pragma once
#include <iostream>
#include <stdio.h>

template <typename K, typename V>
struct Tuple
{
    K key;
    V value;
    int index;
};
template <typename K, typename V>
class Map {
    K *keys;
    V *values;
    int n;
public:
    Map() : keys(nullptr), values(nullptr), n(0) {}

    void Set(const K& key, const V& value) {
        for (int i = 0; i < n; i++) {
            if (keys[i] == key) {
                values[i] = value;
                return;
            }
        }
    }

    bool Get(const K& key, V& value) const {
        for (int i = 0; i < n; i++) {
            if (keys[i] == key) {
                value = values[i];
                return true;
            }
        }
        return false;
    }

    int Count() const {
        return n;
    }

    void Clear() {
        delete[] keys;
        delete[] values;
        n = 0;
    }

    bool Delete(const K& key) {
        int ok = 0;
        for (int i = 0; i <= n; i++)
        {
            if (keys[i] == key)
            {
                ok = 1;
                break;
            }
        }
        if (ok == 0)
            return false;
        n--;
        K* newKey = new K[n];
        V* newValue = new V[n];
        int j = 0;
        for (int i = 0; i <= n; i++)
        {
            if (keys[i] != key)
            {
                newKey[j] = keys[i];
                newValue[j] = values[i];
                j++;
            }
        }
        delete[] keys;
        delete[] values;
        keys = newKey;
        values = newValue;
        return true;
    }

    bool Includes(const Map<K, V>& map) const {
        for (int i = 0; i < map.n; i++) {
            V value;
            if (!map.Get(keys[i], value))
                return false;
            return true;
        }
    }

    V& operator[](K key)
    {
        for (int i = 0; i < n; i++)
        {
            if (keys[i] == key)
                return values[i];
        }
        n++;
        K* newKey = new K[n];
        V* newValue = new V[n];
        for (int i = 0; i < n - 1; i++)
        {
            newKey[i] = keys[i];
            newValue[i] = values[i];
        }
        newKey[n - 1] = key;
        delete[] keys;
        delete[] values;
        keys = newKey;
        values = newValue;

        return values[n - 1];
    }



        //clasa de iterator pentru begin si end

    class Iterator {
        K* keys;
        V* values;
        int index;
    public:
        Iterator(K* keys, V* values, int index) : keys(keys), values(values), index(index) {}

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }

        void operator++() {
            index++;
        }

        auto operator*()
        {
            return Tuple<K, V>{keys[index], values[index], index};
        }

    };

    Iterator begin() {
        return Iterator(keys, values, 0);
    }

    Iterator end() {
        return Iterator(keys, values, n);
    }

};

