const title = document.querySelector(".title h1");

title.style.color = "black";

function handleTitleClick() {
  const currentColor = title.style.color; // getter
  let newColor; // setter

  if (currentColor === "black") {
    newColor = "blue";
  } else {
    newColor = "black";
  }

  title.style.color = newColor; // 최종 할당
}

title.addEventListener("click", handleTitleClick);
