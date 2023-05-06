import sys
import typing
from PyQt5 import QtCore
from PyQt5.QtWidgets import (
    QApplication,
    QMainWindow,
    QPushButton,
    QLabel,
    QLineEdit,
    QComboBox,
    QWidget,
    QVBoxLayout,
    QHBoxLayout,
    QGridLayout,
)
from PyQt5.QtGui import QPixmap


class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        # Widgets
        ###########################################
        # Label - 고정 텍스트 추가
        name = QLabel('Name:')
        pw = QLabel('Password:')

        # Pixmap - 이미지 추가 (QLabel 이용)
        logo_cont = QLabel()
        logo = QPixmap('./assets/ALFSR_logo.png')
        logo_cont.setPixmap(logo)

        # LineEdit - 사용자에게 값 받기
        getName = QLineEdit()
        getPW = QLineEdit()

        # PushButton
        logIn = QPushButton('Log In')

        # ComboBox - 옵션 선택
        versions = QComboBox()
        versions.addItem('v-1.0.0')
        versions.addItem('v-1.1.0')
        versions.addItem('v-1.1.1')
        versions.addItem('v-1.1.2')

        ###########################################
        # Containers
        twoByTwo = QGridLayout()                # 2x2 Grid
        r = QHBoxLayout()                       # Grid + Column
        c1 = QVBoxLayout()                      # logIn + versions
        c2 = QVBoxLayout()                      # Final container

        # Add widgets
        twoByTwo.addWidget(name, 0, 0)
        twoByTwo.addWidget(getName, 0, 1)
        twoByTwo.addWidget(pw, 1, 0)
        twoByTwo.addWidget(getPW, 1, 1)
        c1.addWidget(logIn)
        c1.addWidget(versions)
        c2.addWidget(logo_cont)

        # Combine layers
        r.addLayout(twoByTwo)
        r.addLayout(c1)
        c2.addLayout(r)

        widget = QWidget()
        widget.setLayout(c2)
        self.setCentralWidget(widget)


app = QApplication(sys.argv)
window = MyWindow()
window.show()
app.exec_()
