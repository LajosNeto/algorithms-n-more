/**
 * Hash Table implementation based on chaining approach for collision resolution.
 * Prehash approach : https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1164/handouts/8-Hashing.pdf
 * Prehash approach : https://cp-algorithms.com/string/string-hashing.html
 * Prehash approach : http://www.cse.yorku.ca/~oz/hash.html
 *
 * Author : Lajos Neto.
 * Email : lajosnetogit@gmail.com
 */

import kotlin.math.pow

class HashTable<K, V>(val hashFunction: String = "universal") {
    var tableSize = 8
    var table = IntArray(tableSize)

    fun prehash(key: K) =
        key.toString().mapIndexed { index, char -> char.toInt() * 31.0.pow(index + 1) }.sum().toInt()

    fun hash(key: K): Int {
        return 0
    }

//    private fun expand() {}
//    private fun shrink() {}
//    fun get(key: T): V { return V }
//    fun has(key: T): Boolean { return true }
//    fun put(key: K, value: V) {}
//    fun remove(key: K) {}
}