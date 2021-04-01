/**
 * Hash Table based on chaining tests.
 *
 * Author : Lajos Neto.
 * Email : lajosnetogit@gmail.com
 */

import org.junit.Test
import kotlin.random.Random

class HashTableTest {

    @Test
    fun preHashTest() {
        val hashTable = ChainHashTable<String, Int>()
        assert(hashTable.preHash("a").toInt() == 3007)
        assert(hashTable.preHash("b").toInt() == 3038)
        assert(hashTable.preHash("c").toInt() == 3069)
        assert(hashTable.preHash("d").toInt() == 3100)
        assert(hashTable.preHash("abcd").toInt() == 95398594)
        assert(hashTable.preHash("abdc").toInt() != 95398594)
    }

    @Test
    fun hasKeyTest() {
        val hashTable = ChainHashTable<String, Int>()
        hashTable.put("abcd", 1)
        assert(hashTable.has("abcd"))
        assert(!hashTable.has("abcde"))
        hashTable.put("abcde", 1)
        assert(hashTable.has("abcde"))
        hashTable.put("dcba", 1)
        assert(hashTable.has("dcba"))
    }

    @Test
    fun removeTest() {
        val hashTable = ChainHashTable<Int, String>()
        (1..7).forEach { i -> hashTable.put(i, Random.nextInt().toString()) }
        assert(hashTable.keyCount() == 7)
        hashTable.remove(1)
        assert(hashTable.keyCount() == 6)
        hashTable.remove(1)
        assert(hashTable.keyCount() == 6)
        hashTable.remove(2)
        assert(hashTable.keyCount() == 5)
        hashTable.remove(3)
        assert(hashTable.keyCount() == 4)
    }

    @Test
    fun expandTest() {
        val hashTable = ChainHashTable<Int, String>()
        assert(hashTable.tableSize() == 8)
        (1..7).forEach { i -> hashTable.put(i, Random.nextInt().toString()) }
        assert(hashTable.tableSize() == 8)
        hashTable.put(8, Random.nextInt().toString())
        assert(hashTable.tableSize() == 16)
        (9..15).forEach { i -> hashTable.put(i, Random.nextInt().toString()) }
        assert(hashTable.tableSize() == 16)
        hashTable.put(16, Random.nextInt().toString())
        assert(hashTable.tableSize() == 32)
    }

    @Test
    fun shrinkTest() {
        val hashTable = ChainHashTable<Int, String>()
        assert(hashTable.tableSize() == 8)
        (1..128).forEach { i -> hashTable.put(i, Random.nextInt().toString()) }
        assert(hashTable.tableSize() == 256)
        (64..128).forEach { i -> hashTable.remove(i) }
        assert(hashTable.tableSize() == 128)
        (32..64).forEach { i -> hashTable.remove(i) }
        assert(hashTable.tableSize() == 64)
        (16..32).forEach { i -> hashTable.remove(i) }
        assert(hashTable.tableSize() == 32)
        (8..16).forEach { i -> hashTable.remove(i) }
        assert(hashTable.tableSize() == 16)
        (4..8).forEach { i -> hashTable.remove(i) }
        assert(hashTable.tableSize() == 8)
        (1..4).forEach { i -> hashTable.remove(i) }
        assert(hashTable.tableSize() == 8)
    }

    @Test
    fun expandAndShrinkTest() {
        val hashTable = ChainHashTable<Int, String>()
        (1..128).forEach { i -> hashTable.put(i, Random.nextInt().toString()) }
        assert(hashTable.tableSize() == 256)
        (64..128).forEach { i -> hashTable.remove(i) }
        assert(hashTable.tableSize() == 128)
        (64..128).forEach { i -> hashTable.put(i, Random.nextInt().toString()) }
        assert(hashTable.tableSize() == 256)
        (32..128).forEach { i -> hashTable.remove(i) }
        assert(hashTable.tableSize() == 64)
        (32..64).forEach { i -> hashTable.put(i, Random.nextInt().toString()) }
        assert(hashTable.tableSize() == 128)
        (16..64).forEach { i -> hashTable.remove(i) }
        assert(hashTable.tableSize() == 32)
    }

}