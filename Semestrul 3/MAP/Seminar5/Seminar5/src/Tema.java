public class Tema extends {
    private String desc;
    private String id;

    public Tema(String desc, String id) {
        this.desc = desc;
        this.id = id;
    }

    public String getDesc() {
        return desc;
    }

    public String getId() {
        return id;
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }

    public void setId(String id) {
        this.id = id;
    }

}
