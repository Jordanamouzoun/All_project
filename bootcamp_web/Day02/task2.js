function isValidEmail(email)
{
    const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
    return emailRegex.test(email);
}

const email1 = "example@example.com";
console.log(isValidEmail(email1));  // true

const email2 = "invalid_email.com";
console.log(isValidEmail(email2));  // false