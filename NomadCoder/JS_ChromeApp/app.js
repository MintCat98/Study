function loginSubmit(event) {
  const username = loginInput.value;
  event.preventDefault();
  console.log(username);
  return username;
}

const loginForm = document.querySelector("#login-form");
const loginInput = document.querySelector("#login-form input");

loginForm.addEventListener("submit", loginSubmit);
