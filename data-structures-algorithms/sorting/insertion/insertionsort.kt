/**
 * Insertion sort implementation
 *
 */
fun insertionSort(input: MutableList<Int>) {
    for (i in 0 until input.size) {
      val temp = input[i]
      var j = i
      while (j > 0 && temp < input[j - 1]) {
        input[j] = input[j - 1]
        j--
        specialPrint(input)
      }
      input[j] = temp
      specialPrint(input)
    }
  }
  
  fun specialPrint(input: MutableList<Int>) {
    input.forEach {
      println("=".repeat(it))
    }
  
    println("\n\n\n")
  }
  
  fun main(args: Array<String>) {
  
    val a = mutableListOf(5, 4, 3, 2, 1, 1)
    insertionSort(a)
  //  println(a)
  
  //  val b = mutableListOf(Foo(5), Foo(4), Foo(3), Foo(2), Foo(1), Foo(1))
  //  b.selectionSortBy { it.id }
  //  println(b)
  //
  //  val c = mutableListOf(Foo2("z"), Foo2("v"), Foo2("m"), Foo2("b"), Foo2("a"), Foo2("a"))
  //  c.selectionSortBy { it.id }
  //  println(c)
  
  }