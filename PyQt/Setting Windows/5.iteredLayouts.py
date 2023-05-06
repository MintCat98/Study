import sys
import typing
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QWidget, QVBoxLayout, QGridLayout, QHBoxLayout


class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        # Buttons
        pBtn1 = QPushButton('V1', self)
        pBtn2 = QPushButton('V2', self)
        pBtn3 = QPushButton('V3', self)
        pBtn4 = QPushButton('G1', self)
        pBtn5 = QPushButton('G2', self)
        pBtn6 = QPushButton('G3', self)
        pBtn7 = QPushButton('G4', self)

        # Layouts
        leftVBox = QVBoxLayout()
        leftVBox.addWidget(pBtn1)
        leftVBox.addWidget(pBtn2)
        leftVBox.addWidget(pBtn3)

        rightGridBox = QGridLayout()
        rightGridBox.addWidget(pBtn4, 0, 0)
        rightGridBox.addWidget(pBtn5, 0, 1)
        rightGridBox.addWidget(pBtn6, 1, 0)
        rightGridBox.addWidget(pBtn7, 1, 1)

        outerHBox = QHBoxLayout()
        # 중첩 레이아웃을 쓸 때는 addLayout() 메서드 사용!
        outerHBox.addLayout(leftVBox)
        outerHBox.addLayout(rightGridBox)

        widget = QWidget()
        widget.setLayout(outerHBox)
        self.setCentralWidget(widget)


app = QApplication(sys.argv)
window = MyWindow()
window.show()
app.exec_()
