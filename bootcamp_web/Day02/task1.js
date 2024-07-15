/*
** EPITECH PROJECT, 2023
** Day02
** File description:
** task1.js
*/

function sumOfOddNumbers(arr)
{
    let res = 0;
    arr.forEach((num)=> {
        if (num % 2 != 0)
            res += num
    });
    return res;
}

const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const oddSum = sumOfOddNumbers(numbers);
console.log(oddSum);
