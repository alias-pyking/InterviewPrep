class Node{
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}
class linkedlist{
    constructor() {
        this.head = null;
    }
    function insert(data) {
        if (this.head === null) {
            this.head = new Node(data)
        }
    }
}