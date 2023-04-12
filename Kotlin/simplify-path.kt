class Solution {
    fun simplifyPath(path: String): String {
        val parts = ArrayDeque<String>()
        for (dir in path.split("/")) {
            if (dir.length == 0)
                continue
            if (dir == "..") {
                if (!parts.isEmpty()) {
                    parts.removeLast()
                }
            } else if (dir != ".") {
                parts.addLast(dir)
            }
        }
        return "/" + parts.joinToString("/")
    }
}