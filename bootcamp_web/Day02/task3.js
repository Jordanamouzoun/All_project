function countVowels(words)
{
    const tab = ["a", "e", "i", "o", "u", "y"];
    let b = 0;

    for (let a = 0; a < words.length; a++) {
        if (tab.includes(words[a]) == true)
            b++;
    }
    return b;
}

const str = "Hello, World!";
const vowelCount = countVowels(str);
console.log(vowelCount);