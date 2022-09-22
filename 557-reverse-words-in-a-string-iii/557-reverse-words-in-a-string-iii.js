/**
 * @param {string} s
 * @return {string}
 */

function rev(s, l, r) {
    var str = "";
    while (l <= r){
        str += (s[r--]);
    }
    return str;
}
var reverseWords = function(s) {
    var n = s.length;
    var l = 0;
    var ans = "";
    for (let i = 0; i < n; i++){
        if (s[i] === ' '){
            ans += rev(s, l, i - 1);
            l = i + 1;
            ans += ' ';
        }
        else if (i === n - 1){
            ans += rev(s, l, i);
        }
    }
    return ans;
};