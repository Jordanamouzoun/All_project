function reverseWords(str)
{
    return str.split(" ").reverse().join(" ")
}

const sentence = "Hello, World!";
const reversedSentence = reverseWords(sentence);
console.log(reversedSentence);