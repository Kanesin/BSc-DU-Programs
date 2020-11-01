import java.awt.*;
import java.applet.*;
import java.awt.event.*;
//<applet code="Q28.class" width="100" height="200"> </applet> 
public class Q28 extends Applet implements KeyListener
{
	String str=" ";
	int mx=10,my=10;
	public void init()
	{
		addKeyListener(this);		
	}
	public void keyPressed(KeyEvent e)
	{
		str="key pressed";
		showStatus("Key Pressed");
		setBackground(Color.blue);
		repaint();		
	}
	public void keyTyped(KeyEvent e)
	{
		str="key typed";
		showStatus("Key Typed");
		//str=e.getKeyChar();
		setBackground(Color.red);
		repaint();
	}
	public void keyReleased(KeyEvent e)
	{	
		str="key released";
		showStatus("Key Released");
		setBackground(Color.green);
	}
	public void paint(Graphics ob)
	{
		ob.drawString(str,mx,my);
	}
}
	
