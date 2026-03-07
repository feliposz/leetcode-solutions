/**
 * @param {string[]} emails
 * @return {number}
 */
var numUniqueEmails = function(emails) {
    const unique = new Set()
    for (let email of emails) {
        email = cleanEmail(email)
        unique.add(email)
    }
    return unique.size
};

var cleanEmail = function(email) {
    let [local, domain] = email.split('@')
    local = local.replaceAll(/\+.*$/g, '')
    local = local.replaceAll('.', '')
    return local + '@' + domain
}