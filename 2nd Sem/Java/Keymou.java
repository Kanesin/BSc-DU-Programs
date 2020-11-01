import java.awt.*;
import java.applet.*;
import java.awt.event.*;
//<applet code="Keymou.class" width="100" height="200"> </applet> 
public class Keymou extends Applet implements KeyListener, MouseListener , MouseMotionListener
{
	String str=" ";
	int mx=0,my=0;
	public void init()
	{
		addKeyListener(this);
		addMouseMotionListener(this);
		addMouseListener(this);				
	}
	public void keyPressed(KeyEvent e)
	{
		mx=10;
		my=10;
		str="key pressed";
		showStatus("Key Pressed");
		setBackground(Color.blue);
		repaint();		
	}
	public void keyTyped(KeyEvent e)
	{
		mx=10;
		my=10;
		str="key typed";
		showStatus("Key Typed");
		setBackground(Color.red);
		repaint();
	}
	public void keyReleased(KeyEvent e)
	{	
		mx=10;
		my=10;	
		str="key released";
		showStatus("Key Released");
		setBackground(Color.green);
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
		mx=10;
		my=10;
		str="Mouse Entered";
		setBackground(Color.green);
		repaint();
	}
	public void mouseExited(MouseEvent e)
	{
		mx=10;
		my=10;
		str="Mouse Exited";
		setBackground(Color.red);
		repaint();
	}
	public void mousePressed(MouseEvent e)
	{
		mx=10;
		my=10;
		str="Mouse pressed";
		setBackground(Color.magenta);
		repaint();
	}
	public void mouseReleased(MouseEvent e)
	{
		mx=10;
		my=10;
		str="Mouse Released";
		setBackground(Color.pink);
		repaint();
	}
	public void mouseDragged(MouseEvent e)
	{
		mx=10;
		my=10;
		str="Mouse Dragged";
		setBackground(Color.blue);
		repaint();
	}
	public void mouseMoved(MouseEvent e)
	{
		mx=10;
		my=10;
		str="Mouse Moved";
		setBackground(Color.yellow);
		repaint();
	}
							
	public void paint(Graphics ob)
	{
		mx=20;
		my=20;
		ob.drawString(str,mx,my);
		ob.drawString(str,mx,my);
	}
}
	
