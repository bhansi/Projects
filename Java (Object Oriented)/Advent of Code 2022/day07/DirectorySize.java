package day07;

public class DirectorySize {
	
	private String directory_name;
	private long directory_size;
	
	public DirectorySize(String directory_name, long directory_size) {
		
		this.directory_name = directory_name;
		this.directory_size = directory_size;
		
	}
	
	public String getDirectoryName() {
		return this.directory_name;
	}
	
	public long getDirectorySize() {
		return this.directory_size;
	}
	
	public void setDirectoryName(String directory_name) {
		this.directory_name = directory_name;
	}
	
	public String toString() {
		return String.format("%s : %d", this.directory_name, this.directory_size);
	}

}
