package Ciphers;

public class Beaufort {
	public static void main(String[] args)
	{
		String code="fortification";
		String phrase="defend the east wall of the castle";
		String enc=encrypt(phrase, code);
		System.out.println(enc);
		System.out.println(decrypt(enc, code));
	}
	public static String encrypt(String p, String c)
	{
		String phrase=p.toUpperCase();
		String code=c.toUpperCase();
		String codePhrase="";
		String encryption="";
		phrase=phrase.replaceAll("\\s+","");
		for(int x=0; x<phrase.length(); x+=code.length())
		{
			codePhrase+=code;
		}
		for(int x=0; x<phrase.length(); x++)
		{		
			int shift=codePhrase.charAt(x)-phrase.charAt(x);
			int cypher;
			if(shift>=0)
				cypher=65+shift;
			else
				cypher=91+shift;
			String shiftedChar=Character.toString((char)cypher);
			encryption+=shiftedChar;
		}
		return encryption;
	}
	
	
	public static String decrypt(String p, String c)
	{
		String phrase=p.toUpperCase();
		String code=c.toUpperCase();
		String codePhrase="";
		String decryption="";
		phrase=phrase.replaceAll("\\s+","");
		for(int x=0; x<phrase.length(); x+=code.length())
		{
			codePhrase+=code;
		}
		for(int x=0; x<phrase.length(); x++)
		{
			int shift=codePhrase.charAt(x)-phrase.charAt(x);
			int shifted;
			if(shift>=0)
			{
				shifted=65+shift;
			}
			else
			{
				shifted=91+shift;
			}
			String shiftedChar=Character.toString((char)shifted);
			decryption+=shiftedChar;
		}
		return decryption;
	}
}
