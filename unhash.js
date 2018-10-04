/*
Find a 9 letter string of characters that contains only letters from "acdegilmnoprstuw" such that the hash(the_string) is 956446786872726 if hash is defined by the following pseudo-code:

Int64 hash (String s) {

  Int64 h = 7

  String letters = "acdegilmnoprstuw"

  for(Int32 i = 0; i < s.length; i++) {

    h = (h * 37 + letters.indexOf(s[i]))

  }

  return h

}
 */

const assert = require('assert')

const seed = 7
const prime = 37
const letters = "acdegilmnoprstuw"

const unhash = (hash, acc, letterOffset = 0) => {
  if (hash === seed) return acc
  for (;hash%prime>0;hash--,letterOffset++);
  return unhash(hash/prime, letters[letterOffset] + acc)
}

assert(unhash(680131659347,'') === 'leepadg', '68013165934 !=== leepadg')
assert(unhash(956446786872726,'') === 'trellises', '956446786872726 !=== trellises')
