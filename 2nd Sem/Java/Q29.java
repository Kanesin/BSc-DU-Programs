import java.awt.*;
import java.awt.Frame.*;
import java.applet.*;
public class Q29 extends Frame
{
	String msg="Hello";
	int mx=200,my=200;
	Q29(String title)
	{
		super();
		this.setSize(1500,1500);
		this.setTitle(title);
		this.setVisible(true);
		repaint();
	}
	public void paint (Graphics g)
	{
		g.drawString(msg, mx ,my);
	}
	public static void main(String [] srgs)
	{
		Q29 ob=new Q29("WINDOWS");
	}
}
		