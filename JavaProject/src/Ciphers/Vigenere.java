package Ciphers;

public class Vigenere {	
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
			int shift=codePhrase.charAt(x)-65;
			int start=phrase.charAt(x);
			int shifted=start+shift;
			if(shifted>90)
			{
				shifted=64+(shifted%90);
			}
			String shiftedChar=Character.toString((char)shifted);
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
			int codeInt=codePhrase.charAt(x);
			int encInt=phrase.charAt(x);
			int shift=encInt-codeInt;
			int shifted=65;
			if(shift>0)
			{
				shifted=65+shift;
			}
			else if(shift<0)
			{
				shifted=91+shift;
			}
			String shiftedChar=Character.toString((char)shifted);
			decryption+=shiftedChar;
		}
		return decryption;
	}

}
