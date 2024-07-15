/*
** EPITECH PROJECT, 2023
** bootcamp_web
** File description:
** task6.js
*/

function removeDuplicates(array)
{
    let tab = [];

    for (let a = 0; a < array.length; a++) {
        if (tab.includes(array[a]) == false)
            tab.push(array[a]);
    }
    return tab;
}

const array = [1, 2, 3, 2, 4, 1, 5, 3];
const uniqueArray = removeDuplicates(array);
console.log("Array with duplicates:", array);
console.log("Array without duplicates:", uniqueArray);