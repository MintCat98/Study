const title = document.querySelector(".title h1");

function handleTitleClick() {
  title.style.color = "red";
}
function handleMouseEnter() {
  console.log("mouse enter");
}
function handleMouseLeave() {
  console.log("mouse leave");
}

title.addEventListener("click", handleTitleClick);
title.addEventListener("mouseenter", handleMouseEnter);
title.addEventListener("mouseleave", handleMouseLeave);
