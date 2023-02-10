const title = document.querySelector(".title h1");

function handleTitleClick() {
  const clickClass = "click"; // raw value는 에러의 위험성이 있으니 되도록이면 변수를 설정하자!
  const currentStyle = title.classList;

  if (currentStyle.contains(clickClass)) {
    currentStyle.remove(clickClass);
  } else {
    currentStyle.add(clickClass);
  }
}

title.addEventListener("click", handleTitleClick);
