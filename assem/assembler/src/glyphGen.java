import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintWriter;

public class glyphGen {

	public static void convert(String fileName, String outputFileName, int radix)
	{
		BufferedImage image = javax.imageio.ImageIO.read(new File(fileName));
		PrintWriter out = new PrintWriter(new File(outputFileName));
		out.printf ("memory_initialization_radix=%d;", radix);
		out.println ("memory_initialization_vector=");
		
		StringBuilder bitstream = new StringBuilder();

		System.out.printf ("Processing %s: %dx%d", fileName, image.getWidth(), image.getHeight());

		for (int i = 0; i < 32; i++) // undisplayable characters (below space)
		{
			for (int b = 0; b < 8; b++)
				bitstream.append("00000000");
		}
			
        for (int i = 32; i < 128; i++) // displayable characters (up to DEL)
        {
        	int x = ((i-32) % 16) * 8; 
        	int y = ((i-32) / 16) * 8;
        	
        	for (int py = 0; py < 8; py++)
        	{
        		for (int px = 7; px >= 0; px--)
        		{
        			int c = image.getRGB(x + px,  y + py);
        			if ((c & 0xff) < 20)
        				bitstream.append ("1");
        			else
        				bitstream.append ("0");
        		}
        		
        	}
    		
        		
        }
		for (int i = 128; i < 256; i++)
		{
			for (int b = 0; b < 8; b++)
				bitstream.append("00000000");
		}

		String s = bitstream.toString();
		
		String separator = "";
		for (int i = 0; i < 256 * 4; i++)
		{
			out.println(separator);
			separator = ",";
			out.print(s.substring(i*16, (i+1)*16));
		}
		out.println(";");
		
        out.close();
	}

	public static void main(String[] args) throws Exception 
	{
		if (args.length < 2) 
			System.out.println("Please specify an input (.png), an output file (.coe)")

		String fileName = args[0]; // .png
		String outputFileName = args[1]; // .coe
		int radix = 2; // specify radix: 2 = binary, 10 = decimal, 16 = hex, CURRENTLY ONLY 2 IS SUPPORTED

		convert(fileName, outputFileName);
	}

}
