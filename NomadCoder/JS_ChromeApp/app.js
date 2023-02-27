const logInForm = document.querySelector("#login-form");
const logInInput = document.querySelector("#login-form input");

function logInSubmit(event) {
  event.preventDefault();
  const username = logInInput.value;
  return username;
}

logInForm.addEventListener("submit", logInSubmit);
