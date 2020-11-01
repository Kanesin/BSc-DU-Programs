import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*<applet code="Q30.class" width="200" height="200">
</applet>*/
public class Q30 extends Applet implements ActionListener
{
	String msg=" ";
	public void init()
	{
		Button yes=new Button("Yes");
		Button no=new Button("No");
		add(yes);
		add(no);
		yes.addActionListener(this);
		no.addActionListener(this);
	}
	public void actionPerformed(ActionEvent e)
	{
		String str=e.getActionCommand();
		if(str.equals("Yes"))
		{
			setBackground(Color.red);
			msg="You pressed  yes";
		}
		else
		{
			setBackground(Color.orange);
			msg="You pressed no";
		}
		repaint();
	}
	public void paint(Graphics g)
	{
		g.drawString(msg,60,60);
	}
}