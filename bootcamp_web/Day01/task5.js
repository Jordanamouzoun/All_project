/*
** EPITECH PROJECT, 2023
** bootcamp_web
** File description:
** task5.js
*/

function isalpha(c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'z' || c >= '0' && c <= '9')
        return 0;
    else
        return 1;
}

function isPalindrome(str)
{
    let str1 = "\0";
    for (let a = 0; a < str.length; a++) {
        if (isalpha(str[a]) == 0)
            str1 = str1 + str[a];
    }
    let str3 = str1.toLowerCase();
    let str2 = str3. split(""). reverse(). join("");
    if (str2.localeCompare(str3) == 0)
        return "true";
    else
        return "false";
}

const str = "Noon";
const isPalindromeString = isPalindrome(str);
console.log(`Is "${str}" a palindrome? ${isPalindromeString}`);
