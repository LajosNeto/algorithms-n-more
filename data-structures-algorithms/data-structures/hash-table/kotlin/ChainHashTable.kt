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
    private var tableSize = INITIAL_TABLE_PRIME_SIZE
    private var valueCount = 0
    private var table = Array(tableSize) { mutableListOf<Pair<K, V>>() }

    fun preHash(key: K) =
        key.toString().mapIndexed { index, char -> char.toInt() * PRE_HASH_PRIME.pow(index + 1) }.sum()

    fun hash(key: K): Int {
        val preHashKey = preHash(key)
        val a = Random(RANDOM_SEED).nextInt(0, UNIVERSAL_HASH_PRIME - 1)
        val b = Random(RANDOM_SEED).nextInt(0, UNIVERSAL_HASH_PRIME - 1)
        return ((((a*preHashKey) + b) % UNIVERSAL_HASH_PRIME) % tableSize).toInt()
    }

    fun put(key: K, value: V) {
        val keyHash = hash(key)
        table[keyHash].add(Pair(key, value))
        valueCount += 1
        if (valueCount > tableSize) expand()
    }

    private fun expand() {}
//    private fun shrink() {}
//    private fun closestPrime(after: Int): Int {}
//    fun get(key: K): V { return }
//    fun has(key: K): Boolean { return true }
//    fun remove(key: K) {}

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
        const val INITIAL_TABLE_PRIME_SIZE = 11
        const val RANDOM_SEED = 42
        const val PRE_HASH_PRIME = 31.0
        const val UNIVERSAL_HASH_PRIME = 3079
    }
}