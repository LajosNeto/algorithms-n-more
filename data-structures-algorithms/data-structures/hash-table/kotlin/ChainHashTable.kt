/**
 * Hash Table implementation based on chaining approach for collision resolution.
 *
 * Resources for implementation and values choices :
 * Prehash approach : https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1164/handouts/8-Hashing.pdf
 * Prehash approach : https://cp-algorithms.com/string/string-hashing.html
 * Prehash approach : http://www.cse.yorku.ca/~oz/hash.html
 * Universal hashing : https://www.cs.cmu.edu/~avrim/451f11/lectures/lect1004.pdf
 * Universal hashing primes table : https://planetmath.org/goodhashtableprimes
 *
 * Author : Lajos Neto.
 * Email : lajosnetogit@gmail.com
 */

import kotlin.math.pow
import kotlin.random.Random

class ChainHashTable<K, V>(val hashFunction: String = "universal") {
    private var tableSize = MIN_TABLE_SIZE
    private var keyCount = 0
    private var table = Array(tableSize) { mutableListOf<Pair<K, V>>() }

    fun preHash(key: K) =
        key.toString().mapIndexed { index, char -> char.toInt() * PRE_HASH_PRIME.pow(index + 1) }.sum()

    fun hash(key: K): Int {
        val a = Random(RANDOM_SEED).nextInt(0, UNIVERSAL_HASH_PRIME - 1)
        val b = Random(RANDOM_SEED).nextInt(0, UNIVERSAL_HASH_PRIME - 1)
        return ((((a*preHash(key)) + b) % UNIVERSAL_HASH_PRIME) % tableSize).toInt()
    }

    fun put(key: K, value: V) {
        if (!has(key)) {
            table[hash(key)].add(Pair(key, value))
            keyCount += 1
            if (keyCount >= tableSize) expand()
        }
    }

    fun remove(key: K) {
        val keyHash = hash(key)
        table[keyHash].forEachIndexed { index, node ->
            if (node.first == key) {
                table[keyHash].removeAt(index)
                keyCount -= 1
                if (keyCount <= tableSize / 4) shrink()
                return
            }
        }
    }

    private fun expand() { reshape(tableSize*2) }

    private fun shrink() { if (tableSize > MIN_TABLE_SIZE) reshape(tableSize/2) }

    private fun reshape(newSize: Int) {
        tableSize = newSize
        val resizedTable = Array(tableSize) { mutableListOf<Pair<K, V>>() }
        table.forEach { slot ->
            slot.forEach { node ->
                val keyHash = hash(node.first)
                resizedTable[keyHash].add(node)
            }
        }
        table = resizedTable
    }

    fun has(key: K): Boolean {
        table[hash(key)].forEach { node ->
            if (node.first == key) return true
        }
        return false
    }

    fun get(key: K): V? {
        table[hash(key)].forEach { node ->
            if(node.first == key) return node.second
        }
        return null
    }

    fun keyCount() = keyCount

    fun tableSize() = tableSize

    fun testPrint() {
        var collidedIndexes = 0
        var collisionCount = 0
        table.forEachIndexed { index, bucket ->
            println("Bucket $index : $bucket")
            if (bucket.size > 1) {
                collidedIndexes +=1
                collisionCount += bucket.size
            }
        }
        println("==== COLLIDED INDEXES : $collidedIndexes with TOTAL COLLISIONS : ${collisionCount - collidedIndexes} ====")
    }

    companion object {
        const val MIN_TABLE_SIZE = 8
        const val RANDOM_SEED = 42
        const val PRE_HASH_PRIME = 31.0
        const val UNIVERSAL_HASH_PRIME = 3079
    }
}