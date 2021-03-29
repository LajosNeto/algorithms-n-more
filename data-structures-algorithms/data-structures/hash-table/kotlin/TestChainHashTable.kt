/**
 * Hash Table based on chaining tests.
 *
 * Author : Lajos Neto.
 * Email : lajosnetogit@gmail.com
 */

import org.junit.Test

class HashTableTest {

    @Test
    fun preHashTest() {
        val hashTable = HashTable<String, Int>()
        assert(hashTable.prehash("a") == 3007)
        assert(hashTable.prehash("b") == 3038)
        assert(hashTable.prehash("c") == 3069)
        assert(hashTable.prehash("d") == 3100)
        assert(hashTable.prehash("abcd") == 95398594)
        assert(hashTable.prehash("abdc") != 95398594)
    }

}