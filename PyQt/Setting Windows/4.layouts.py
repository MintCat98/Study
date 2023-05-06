import sys
import typing
from PyQt5 import QtCore
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QWidget, QVBoxLayout, QGridLayout


class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        ###############################################################

        # # Absolute Position - 윈도우 사이즈를 조절해도 버튼의 위치와 크기가 고정되어 있음 (좌상단 꼭짓점을 기준으로)
        # pBtn1 = QPushButton('Abs. Position', self)
        # pBtn2 = QPushButton('Abs. Position', self)

        # pBtn1.resize(100, 20)
        # pBtn2.resize(100, 20)
        # pBtn1.move(10, 10)
        # pBtn2.move(10, 50)

        ###############################################################

        # # QVBoxLayout을 이용한 상대 위치 - 윈도우 사이즈를 조절하면 버튼의 위치와 크기가 바뀜
        # pBtn3 = QPushButton('Rel. Position', self)
        # pBtn4 = QPushButton('Rel. Position', self)

        # '''
        # QMainWindow를 상속받는 경우에는 QWidget이 기본적으로 있어서 다음과 같이 구조가 짜여짐
        # QWidget을 상속받는 경우에는 가장 밖의 Window가 없음

        # QVBoxLayout은 위젯을 수직으로 배치할 때 사용하는 컨테이너
        # 플러터의 columns 클래스랑 유사한 듯

        # QHBoxLayout은 위젯을 수평으로 배치할 때 사용하는 컨테이너임을 참고
        # 코드 작성은 QV와 똑같음

        # ----Window----------------------------
        # | ----QWidget----------------------- |
        # | | ----QVBoxLayout--------------- | |
        # | | |                            | | |
        # | | |         B u t t o n        | | |
        # | | |                            | | |
        # | | ------------------------------ | |
        # | ---------------------------------- |
        # --------------------------------------
        # '''
        # layout = QVBoxLayout()          # Make an instance
        # layout.addWidget(pBtn3)         # Add buttons to the container
        # layout.addWidget(pBtn4)

        # # 여기부터는 어떤 클래스를 상속받느냐에 따라 약간 다름 (지금은 QMainWindow 기준)
        # widget = QWidget()                      # Make an instance
        # # layout 컨테이너를 widget 컨테이너 안에 배치
        # widget.setLayout(layout)
        # # widget 컨테이너를 윈도우 안에 배치
        # self.setCentralWidget(widget)

        ###############################################################

        # QGridLayout - 격자 공간 분할 (얘도 상대 위치)
        pBtn5 = QPushButton('Grid Position', self)
        pBtn6 = QPushButton('Grid Position', self)
        pBtn7 = QPushButton('Grid Position', self)
        pBtn8 = QPushButton('Grid Position', self)

        layout2 = QGridLayout()         # Make an instance
        layout2.addWidget(pBtn5, 0, 0)
        layout2.addWidget(pBtn6, 0, 1)
        layout2.addWidget(pBtn7, 1, 0)
        layout2.addWidget(pBtn8, 1, 1)

        widget = QWidget()
        widget.setLayout(layout2)
        self.setCentralWidget(widget)


app = QApplication(sys.argv)
window = MyWindow()
window.show()
app.exec_()
