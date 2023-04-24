#include "mainwidget.h"
#include <QFileDialog>
#include <QLabel>

MainWidget::MainWidget() {
  m_main_layout = new QGridLayout();
  m_paint_widget = new Draw();

  this->setLayout(m_main_layout);
  this->resize(1024, 1024);

  x_minus = createButton("Left");
  x_minus->setShortcut(QKeySequence(Qt::Key_Left));
  connect(x_minus, &QPushButton::clicked, m_paint_widget, &Draw::left_move);

  x_plus = createButton("Right");
  x_plus->setShortcut(QKeySequence(Qt::Key_Right));
  connect(x_plus, &QPushButton::clicked, m_paint_widget, &Draw::right_move);

  y_plus = createButton("Up");
  y_plus->setShortcut(QKeySequence(Qt::Key_Up));
  connect(y_plus, &QPushButton::clicked, m_paint_widget, &Draw::up_move);

  y_minus = createButton("Down");
  y_minus->setShortcut(QKeySequence(Qt::Key_Down));
  connect(y_minus, &QPushButton::clicked, m_paint_widget, &Draw::down_move);

  z_plus = createButton("Inside");
  connect(z_plus, &QPushButton::clicked, m_paint_widget, &Draw::in_move);

  z_minus = createButton("Outside");
  connect(z_minus, &QPushButton::clicked, m_paint_widget, &Draw::out_move);

  x_clockwise = createButton("Rotate x"); // QKeySequence(Qt::Key_9
  x_clockwise->setShortcut(QKeySequence(Qt::Key_7));
  connect(x_clockwise, &QPushButton::clicked, m_paint_widget, &Draw::turn_x);

  x_counterclockwise = createButton("Rotate -x");
  x_counterclockwise->setShortcut(QKeySequence(Qt::Key_8));
  connect(x_counterclockwise, &QPushButton::clicked, m_paint_widget,
          &Draw::turn_counter_x);

  y_clockwise = createButton("Rotate y");
  y_clockwise->setShortcut(QKeySequence(Qt::Key_4));
  connect(y_clockwise, &QPushButton::clicked, m_paint_widget, &Draw::turn_y);

  y_counterclockwise = createButton("Rotate -y");
  y_counterclockwise->setShortcut(QKeySequence(Qt::Key_5));
  connect(y_counterclockwise, &QPushButton::clicked, m_paint_widget,
          &Draw::turn_counter_y);

  z_clockwise = createButton("Rotate z");
  z_clockwise->setShortcut(QKeySequence(Qt::Key_1));
  connect(z_clockwise, &QPushButton::clicked, m_paint_widget, &Draw::turn_z);

  z_counterclockwise = createButton("Rotate -z");
  z_counterclockwise->setShortcut(QKeySequence(Qt::Key_2));
  connect(z_counterclockwise, &QPushButton::clicked, m_paint_widget,
          &Draw::turn_counter_z);

  scale_plus = createButton("+");
  scale_plus->setShortcut(QKeySequence(Qt::Key_Plus));
  connect(scale_plus, &QPushButton::clicked, m_paint_widget, &Draw::scale_plus);

  scale_minus = createButton("-");
  scale_minus->setShortcut(QKeySequence(Qt::Key_Minus));
  connect(scale_minus, &QPushButton::clicked, m_paint_widget,
          &Draw::scale_minus);

  file_select = createButton("Select File");
  connect(file_select, &QPushButton::clicked, m_paint_widget,
          &Draw::select_file);

  QCheckBox *check = new QCheckBox("Perspective on", this);
  connect(check, &QCheckBox::stateChanged, m_paint_widget, &Draw::perspective_change);

  m_main_layout->addWidget(m_paint_widget, 0, 0, 18, 20);
  m_main_layout->addWidget(x_minus, 18, 0, 2, 1);
  m_main_layout->addWidget(x_plus, 18, 1, 2, 1);
  m_main_layout->addWidget(y_plus, 18, 3, 2, 1);
  m_main_layout->addWidget(y_minus, 18, 4, 2, 1);
  m_main_layout->addWidget(z_plus, 18, 5, 2, 1);
  m_main_layout->addWidget(z_minus, 18, 6, 2, 1);
  m_main_layout->addWidget(x_clockwise, 18, 8, 1, 2);
  m_main_layout->addWidget(x_counterclockwise, 19, 8, 1, 2);
  m_main_layout->addWidget(y_clockwise, 18, 10, 1, 2);
  m_main_layout->addWidget(y_counterclockwise, 19, 10, 1, 2);
  m_main_layout->addWidget(z_clockwise, 18, 12, 1, 2);
  m_main_layout->addWidget(z_counterclockwise, 19, 12, 1, 2);
  m_main_layout->addWidget(scale_plus, 18, 18, 2, 1);
  m_main_layout->addWidget(scale_minus, 18, 19, 2, 1);
  m_main_layout->addWidget(file_select, 20, 0, 1, 1);
  m_main_layout->addWidget(check, 20, 1, 1, 1);

  this->setWindowTitle("3D_View");
}

MyButton *MainWidget::createButton(QString text) {
  MyButton *button = new MyButton(text);
  return button;
}
