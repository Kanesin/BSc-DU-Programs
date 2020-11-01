import java.awt.*;
import java.applet.*;
/*<applet code="Q25" width=100 height=20>
</applet>*/
public class Q25 extends Applet implements Runnable
{
	Font f=new Font("Arial",Font.BOLD,10);
	int x=10;
	String msg="Kane's Distinction";
	public void init()
	{
		setBackground(Color.pink);
	}
	public void start()
	{
		Thread t=new Thread(this);
		t.start();
	}
	public void run()
	{
		while(true)
		try
		{
			repaint();
			Thread.sleep(50);
		}
		catch(Exception e)
		{
		}
	}
	public void paint(Graphics g)
	{
		g.setFont(f);
		g.drawString(msg,x,20);
		x+=1;
		if(x>=90)
		{
			x=10;
		}
	}
}
