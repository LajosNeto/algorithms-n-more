"""
Hash Table data structure tests
"""

# Author: 
# Lajos Neto <lajosnetogit@gmail.com>


import pytest
from hash_table import HashTable

def test_put():
    ht = HashTable()
    ht.put("James Bond", 982268945)
    ht.put("Jon Snow", 981275678)
    ht.put("Princess Zelda", 987651123)
    ht.put("Carmen Sandiego", 981112365)
    assert(ht._slots == [
        [('Carmen Sandiego', 981112365)],
        [],
        [],
        [('James Bond', 982268945)],
        [],
        [],
        [('Jon Snow', 981275678)],
        [('Princess Zelda', 987651123)]])
    ht.put("Link the Hero", 981112345)
    ht.put("Tingle the green", 987652234)
    ht.put("Kin the golden", 36424852)
    assert(ht._slots == [
        [('Carmen Sandiego', 981112365)],
        [],
        [],
        [('James Bond', 982268945)],
        [('Kin the golden', 36424852)],
        [('Link the Hero', 981112345), ('Tingle the green', 987652234)],
        [('Jon Snow', 981275678)],
        [('Princess Zelda', 987651123)]])
    ht.put("Kin the golden", 11111111)
    assert(ht._slots == [
        [('Carmen Sandiego', 981112365)],
        [],
        [],
        [('James Bond', 982268945)],
        [('Kin the golden', 36424852)],
        [('Link the Hero', 981112345), ('Tingle the green', 987652234)],
        [('Jon Snow', 981275678)],
        [('Princess Zelda', 987651123)]])
    ht.put('Clarinha, the little snow', 11111111)
    assert(ht._slots == [
        [('Carmen Sandiego', 981112365)],
        [],
        [],
        [('James Bond', 982268945)],
        [('Kin the golden', 36424852), ('Clarinha, the little snow', 11111111)],
        [('Link the Hero', 981112345), ('Tingle the green', 987652234)],
        [('Jon Snow', 981275678)],
        [('Princess Zelda', 987651123)]])

def test_get():
    ht = HashTable()
    ht.put("James Bond", 982268945)
    ht.put("Jon Snow", 981275678)
    ht.put("Princess Zelda", 987651123)
    ht.put("Carmen Sandiego", 981112365)
    ht.put("Link the Hero", 981112345)
    ht.put("Tingle the green", 987652234)
    ht.put("Kin the golden", 36424852)
    assert(ht.get("Kin the golden") == 36424852)
    assert(ht.get("Link the Hero") == 981112345)
    assert(ht.get("Zant Usurper King") == None)
    assert(ht.get("Zant Usurper King", -1) == -1)

def test_exist():
    ht = HashTable()
    ht.put("James Bond", 982268945)
    ht.put("Jon Snow", 981275678)
    ht.put("Princess Zelda", 987651123)
    ht.put("Carmen Sandiego", 981112365)
    ht.put("Link the Hero", 981112345)
    ht.put("Tingle the green", 987652234)
    ht.put("Kin the golden", 36424852)
    assert(ht.exist("James Bond") == True)
    assert(ht.exist("Princess Zelda") == True)
    assert(ht.exist("Kin the golden") == True)
    assert(ht.exist("Link the Hero") == True)
    assert(ht.exist("Non existing 1") == False)
    assert(ht.exist("Non existing 2") == False)
    assert(ht.exist("Non existing 3") == False)
    assert(ht.exist("Non existing 4") == False)

def test_remove():
    ht = HashTable()
    ht.put("James Bond", 982268945)
    ht.put("Jon Snow", 981275678)
    ht.put("Princess Zelda", 987651123)
    ht.put("Carmen Sandiego", 981112365)
    ht.put("Link the Hero", 981112345)
    ht.put("Tingle the green", 987652234)
    ht.put("Kin the golden", 36424852)
    assert(ht.remove("Jon Snow") == ("Jon Snow", 981275678))
    assert(ht.remove("Carmen Sandiego") == ("Carmen Sandiego", 981112365))
    assert(ht.remove("Non existing name") == None)
    assert(ht.remove("Non existing name", -1) == -1)

def test_expand():
    ht = HashTable()
    assert(ht._len == 0)
    assert(ht._size == 8)
    ht.put("James Bond", 982268945)
    ht.put("Jon Snow", 981275678)
    ht.put("Princess Zelda", 987651123)
    ht.put("Carmen Sandiego", 981112365)
    ht.put("Link the Hero", 981112345)
    ht.put("Tingle the green", 987652234)
    ht.put("Kin the golden", 36424852)
    ht.put('Clarinha, the little snow', 11111111)
    assert(ht._len == 8)
    assert(ht._size == 8)
    assert(ht._slots == [
        [('Carmen Sandiego', 981112365)],
        [],
        [],
        [('James Bond', 982268945)],
        [('Kin the golden', 36424852), ('Clarinha, the little snow', 11111111)],
        [('Link the Hero', 981112345), ('Tingle the green', 987652234)],
        [('Jon Snow', 981275678)],
        [('Princess Zelda', 987651123)]])
    ht.put('Pepeta', 22222222)
    assert(ht._len == 9)
    assert(ht._size == 16)
    assert(ht._slots == [
        [('Carmen Sandiego', 981112365)],
        [],
        [],
        [('James Bond', 982268945)],
        [('Clarinha, the little snow', 11111111)],
        [('Tingle the green', 987652234)],
        [],
        [('Princess Zelda', 987651123)],
        [],
        [],
        [],
        [],
        [('Kin the golden', 36424852)],
        [('Link the Hero', 981112345)],
        [('Jon Snow', 981275678)],
        [('Pepeta', 22222222)]])