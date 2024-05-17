fun solve() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toLong() }

    var res = 0L
    var i = 0
    while (i < n) {
        if (a[i] != 0L) {
            var cnt = 0
            var ok = true
            var mx = Long.MIN_VALUE
            var sum = 0L
            while (i < n && a[i] != 0L) {
                sum += a[i]
                cnt++
                if (ok) mx = maxOf(mx, a[i])
                ok = !ok
                i++
            }
            if (cnt % 2 == 0) {
                res += 2 * sum
            } else {
                if (cnt == 1) res += sum
                else res += 2 * sum - mx
            }
            i--
        }
        i++
    }

    println(res)
}

fun main() {
    var tc = 1
    readLine()?.toInt()?.let { tc = it }
    repeat(tc) {
        solve()
    }
}
