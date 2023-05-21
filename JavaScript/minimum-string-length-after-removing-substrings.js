/**
 * @param {string} s
 * @return {number}
 */
var minLength = function(s) {
    var clearString = function(s) {
        while (s.indexOf("AB") >= 0 || s.indexOf("CD") >= 0) {
            s = s.replace("AB", "").replace("CD", "")
        }
        return s
    }
    return clearString(s).length
};