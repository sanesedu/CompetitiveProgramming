
fun merge(left: List<Long>, right: List<Long>): List<Long> {
    var il = 0
    var ir = 0
    var res: MutableList<Long> = mutableListOf()

    while(il < left.count() && ir < right.count()) {
        if(left[il] <= right[ir]) {
            res.add(left[il])
            ++il
        } else {
            res.add(right[ir])
            ++ir
        }
    }

    while(il < left.count()) {
        res.add(left[il])
        ++il
    }

    while(ir < right.count()) {
        res.add(right[ir])
        ++ir
    }

    return res
}

fun mergeSort(list: List<Long>): List<Long> {
    if(list.size <= 1) {
        return list
    }

    var middle = list.size/2
    var left = list.subList(0, middle)
    var right = list.subList(middle, list.size)

    return merge(mergeSort(left), mergeSort(right))
}

fun main(args: Array<String>) {
    var (n, k) = readLine()!!.split(" ").map{it.toInt()}
    var inp: List<Long> = readLine()!!.split(" ").map{it.toLong()}

    var arr = mergeSort(inp)
    
    if(k == 0) {        
        if(arr[0] != 1L) {
            println(1)
        } else {
            println(-1)
        }       
    } else if(k < n && arr[k] == arr[k-1]) {
        println(-1)
    } else {
        println(arr[k-1])
    }
}
