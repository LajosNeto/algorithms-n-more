/**
 * Selection sort implementation
 *
 */
fun selectionSort(input: MutableList<Int>): MutableList<Int> {
    for (i in 0 until input.size) {
      var smallerPosition = i
      for (j in i + 1 until input.size) {
        if (input[j] <= input[smallerPosition]) {
          smallerPosition = j
        }
      }
      val temp = input[smallerPosition]
      input[smallerPosition] = input[i]
      input[i] = temp
    }
    return input
  }
  
  fun <T, R : Comparable<R>> MutableIterable<T>.selectionSortBy(comparable: (T) -> R): MutableIterable<T> {
    val size = (this as MutableList).size
    for (i in 0 until size) {
      var smallerPosition = i
      for (j in i + 1 until size) {
        if (comparable(this[j]) <= comparable(this[smallerPosition])) {
          smallerPosition = j
        }
      }
      val temp = this[smallerPosition]
      this[smallerPosition] = this[i]
      this[i] = temp
    }
    return this
  }
  
  data class Foo(
    val id: Int
  )
  
  data class Foo2(
    val id: String
  )
  
  
  fun main(args: Array<String>) {
  //  println(sort(mutableListOf(5, 4, 3, 2, 1, 1)))
  //  println(mutableListOf(5, 4, 3, 2, 1, 1).selectionSortBy { it })
  
    val a = mutableListOf(5, 4, 3, 2, 1, 1)
    selectionSort(a)
    println(a)
  
    val b = mutableListOf(Foo(5), Foo(4), Foo(3), Foo(2), Foo(1), Foo(1))
    b.selectionSortBy { it.id }
    println(b)
  
    val c = mutableListOf(Foo2("z"), Foo2("v"), Foo2("m"), Foo2("b"), Foo2("a"), Foo2("a"))
    c.selectionSortBy { it.id }
    println(c)
  
  //  mutableListOf(1).selectionSortBy { it }
  //  mutableListOf(Foo(1)).selectionSortBy { it.id }
  }