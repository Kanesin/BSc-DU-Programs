import java.awt.*;
import java.applet.*;
import java.awt.event.*;
//<applet code="Q27.class" width="100" height="200"> </applet> 
public class Q27 extends Applet implements MouseListener , MouseMotionListener
{
	String str="String";
	int mx=0,my=0;
	public void init()
	{
		addMouseMotionListener(this);
		addMouseListener(this);		
	}
	public void mouseClicked(MouseEvent e)
	{
		mx=10;
		my=10;
		setBackground(Color.blue);
		repaint();
	}

	public void mouseEntered(MouseEvent e)
	{
		str="Mouse Entered";
		setBackground(Color.green);
		repaint();
	}
	public void mouseExited(MouseEvent e)
	{
		str="Mouse Exited";
		setBackground(Color.red);
		repaint();
	}
	public void mousePressed(MouseEvent e)
	{
		str="Mouse pressed";
		setBackground(Color.magenta);
		repaint();
	}
	public void mouseReleased(MouseEvent e)
	{
		str="Mouse Released";
		setBackground(Color.pink);
		repaint();
	}
	public void mouseDragged(MouseEvent e)
	{
		str="Mouse Dragged";
		setBackground(Color.blue);
		repaint();
	}
	public void mouseMoved(MouseEvent e)
	{
		str="Mouse Moved";
		setBackground(Color.yellow);
		repaint();
	}
							
	public void paint(Graphics ob)
	{
		ob.drawString(str,mx,my);
	}
}

