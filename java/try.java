import java.io.FileInputStream;  
public class try {  
     public static void main(String args[]){    
          try{    
            FileInputStream source=new FileInputStream("source.txt");    
            int i=0;    
            while((i=source.read())!=-1){    
             System.out.print((char)i);    
            }    
            source.close();    
          }catch(Exception e){System.out.println(e);}    
         }    
        }