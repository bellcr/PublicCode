package Ciphers;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class finalProgram {
	private JComboBox cipherBox;
	private JLabel cipherLabel;
	private JCheckBox fileCheck, outputCheck;
	private JTextArea enteredText, enteredKey, outputText, outputFileText;
	private JButton encryptButton, decryptButton;
	private JScrollPane enterScroll, outputScroll;

	public finalProgram() {
		JFrame frame = new JFrame("Encryption Program");
		String[] cipherList = { "Autokey", "Beaufort", "Vigenere" };

		cipherLabel = new JLabel("Cipher");
		cipherLabel.setSize(100, 100);

		cipherBox = new JComboBox(cipherList);
		cipherBox.setSize(100, 100);

		fileCheck = new JCheckBox("Read from file");
		fileCheck.setSize(100, 100);

		enteredKey = new JTextArea("Enter the cipher Key", 1, 20);
		enteredText = new JTextArea("Enter file name or Text", 5, 20);
		enteredText.setLineWrap(true);
		enterScroll=new JScrollPane(enteredText);
		
		outputCheck = new JCheckBox("Output to file");
		outputCheck.setSize(100, 100);

		outputFileText = new JTextArea("Enter file name ", 1, 20);

		outputText = new JTextArea("Press Encrypt/Decrypt", 5, 20);
		outputText.setLineWrap(true);
		outputScroll=new JScrollPane(outputText);
		
		encryptButton = new JButton("Encrypt");
		encryptButton.setSize(100, 100);
		decryptButton = new JButton("Decrypt");
		decryptButton.setSize(100, 100);

		encryptButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				String output;
				String key = enteredKey.getText();
				String text = "";
				if (!fileCheck.isSelected()) {
					text = enteredText.getText();

				} else {
					try {
						Scanner scanner = new Scanner(new File(enteredText.getText()));
						text = scanner.useDelimiter("\\A").next();
						scanner.close();
					} catch (Exception ex) {
						outputText.setText(ex.getMessage());
					}
				}
				if (cipherBox.getSelectedIndex() == 0) {
					output = Autokey.encrypt(text, key);
				} else if (cipherBox.getSelectedIndex() == 1) {
					output = Beaufort.encrypt(text, key);
				} else {
					output = Vigenere.encrypt(text, key);
				}
				if (!outputCheck.isSelected()) {
					outputText.setText(output);
				} else {
					try {
						PrintWriter out = new PrintWriter(outputFileText.getText());
						out.println(output);
						out.close();
					} catch (Exception ex) {
						outputText.setText(ex.getMessage());
					}
				}
			}
		});
		decryptButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				String output;
				String key = enteredKey.getText();
				String text = "";
				if (!fileCheck.isSelected()) {
					text = enteredText.getText();

				} else {
					try {
						Scanner scanner = new Scanner(new File(enteredText.getText()));
						text = scanner.useDelimiter("\\A").next();
						scanner.close();
					} catch (Exception ex) {
						outputText.setText(ex.getMessage());
					}
				}
				if (cipherBox.getSelectedIndex() == 0) {
					output = Autokey.decrypt(text, key);
				} else if (cipherBox.getSelectedIndex() == 1) {
					output = Beaufort.decrypt(text, key);
				} else {
					output = Vigenere.decrypt(text, key);
				}
				if (!outputCheck.isSelected()) {
					outputText.setText(output);
				} else {
					try {
						PrintWriter out = new PrintWriter(outputFileText.getText());
						out.println(output);
						out.close();
					} catch (Exception ex) {
						outputText.setText(ex.getMessage());
					}
				}
			}
		});

		JPanel contentPane = new JPanel(new FlowLayout());
		contentPane.add(cipherLabel);
		contentPane.add(cipherBox);
		contentPane.add(fileCheck);
		contentPane.add(enteredKey);
		contentPane.add(enterScroll);
		contentPane.add(outputCheck);
		contentPane.add(outputFileText);
		contentPane.add(encryptButton);
		contentPane.add(decryptButton);
		contentPane.add(outputScroll);

		frame.setContentPane(contentPane);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(300, 400);
		frame.setResizable(false);
		frame.setVisible(true);
	}

	public static void main(String[] args) {
		finalProgram run = new finalProgram();
	}

}
