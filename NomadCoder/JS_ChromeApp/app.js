const title = document.querySelector(".title h1");

function handleTitleClick() {
  title.classList.toggle("clickColor");
}

title.addEventListener("click", handleTitleClick);
