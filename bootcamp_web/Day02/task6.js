/*
** EPITECH PROJECT, 2023
** Day02
** File description:
** task1.js
*/

function calculateSum(arr)
{
    let res = 0;
    arr.forEach((num)=> {res += num});
    return res;
}

const numbers = [1, 2, 3, 4, -5];
const sum = calculateSum(numbers);
console.log(sum);
