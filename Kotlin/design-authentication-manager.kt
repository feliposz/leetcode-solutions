class AuthenticationManager(val timeToLive: Int) {

    val tokens = mutableMapOf<String,Int>()

    fun generate(tokenId: String, currentTime: Int) {
        tokens[tokenId] = currentTime + timeToLive
    }

    fun renew(tokenId: String, currentTime: Int) {
        val expirationTime = tokens.getOrElse(tokenId, { currentTime  })
        if (expirationTime > currentTime) {
            tokens[tokenId] = currentTime + timeToLive
        } else {
            //println("time: $currentTime, ignored renewal for $tokenId ($expirationTime)")
        }
    }

    fun countUnexpiredTokens(currentTime: Int): Int {
        //val tokensStr = tokens.entries.joinToString {"${it.key}: ${it.value}"}
        //println("time: $currentTime, tokens: $tokensStr")
        return tokens.values.count { it > currentTime }
    }

}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * var obj = AuthenticationManager(timeToLive)
 * obj.generate(tokenId,currentTime)
 * obj.renew(tokenId,currentTime)
 * var param_3 = obj.countUnexpiredTokens(currentTime)
 */