// 202301558 김결
package a3;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class GraphicsDrawTriMouseEx extends JFrame {
	GraphicsDrawTriMouseEx() {
		setTitle("Draw triangle using mouse");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setContentPane(new MyPanel());
		setSize(400, 400);
		setVisible(true);
	}

	public static void main(String [] args) {
		new GraphicsDrawTriMouseEx();
	}

	class MyPanel extends JPanel {
	     int cnt_p = 0;
	     Point p1 = null;
	     Point p2 = null;
	     Point p3 = null;
	     Point dragStart = null;

	     public MyPanel() {
	         MyMouseListener listener = new MyMouseListener();

	         addMouseListener(listener);
	         addMouseMotionListener(listener);
	     }

	     class MyMouseListener extends MouseAdapter {
	         public void mousePressed(MouseEvent e) {
	             if (cnt_p == 0) {
	                 p1 = e.getPoint();
	             } else if (cnt_p == 1) {
	                 p2 = e.getPoint();
	             } else if (cnt_p == 2) {
	                 p3 = e.getPoint();
	             }

	             cnt_p++;
	             repaint();
	         }

	         public void mouseDragged(MouseEvent e) {
	             if (dragStart == null) {
	                 dragStart = e.getPoint();
	             }

	             int dx = e.getX() - dragStart.x;
	             int dy = e.getY() - dragStart.y;

	             if (p1 != null) {
	                 p1.setLocation(p1.x + dx, p1.y + dy);
	             }
	             if (p2 != null) {
	                 p2.setLocation(p2.x + dx, p2.y + dy);
	             }
	             if (p3 != null) {
	                 p3.setLocation(p3.x + dx, p3.y + dy);
	             }

	             dragStart = e.getPoint();
	             repaint();
	         }
	     }

	     public void paintComponent(Graphics g) {
	         super.paintComponent(g);
	         g.setColor(Color.BLUE);

	         if (p1 != null) {
	             g.drawOval(p1.x - 5, p1.y - 5, 10, 10);
	         }
	         if (p2 != null) {
	             g.drawOval(p2.x - 5, p2.y - 5, 10, 10);
	         }
	         if (p3 != null) {
	             g.drawOval(p3.x - 5, p3.y - 5, 10, 10);
	             g.drawLine(p1.x, p1.y, p2.x, p2.y);
	             g.drawLine(p2.x, p2.y, p3.x, p3.y);
	             g.drawLine(p3.x, p3.y, p1.x, p1.y);
	         }
	     }
	 }
	}