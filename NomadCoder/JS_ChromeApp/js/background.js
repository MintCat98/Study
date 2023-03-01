const imgs = ["0.jpg", "1.jpg", "2.jpg"];

const lengthImgArr = imgs.length;
const imgNum = Math.floor(Math.random() * lengthImgArr);

const todaysBGImg = imgs[imgNum];

// HTML 요소 추가
const bgImg = document.createElement("img");
bgImg.src = `img/${todaysBGImg}`;
document.body.appendChild(bgImg);
