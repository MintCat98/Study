const imgs = ["0.jpg", "1.jpg", "2.jpg"];

const lengthImgArr = imgs.length;
const imgNum = Math.floor(Math.random() * lengthImgArr);

const todaysBGImg = imgs[imgNum];

// HTML μμ μΆκ°
const bgImg = document.createElement("img");
bgImg.src = `img/${todaysBGImg}`;
document.body.appendChild(bgImg);
