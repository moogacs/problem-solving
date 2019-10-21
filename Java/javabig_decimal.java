Arrays.sort(s, Collections.reverseOrder(new Comparator<String>() {
    @Override
    public int compare(String a1, String a2) {
        //convert to big decimal inside comparator
        //so permanent string values are never changed
        //aka you only use the BigDecimal values to 
        //compare the strings!
        BigDecimal a = new BigDecimal(a1);
        BigDecimal b = new BigDecimal(a2);
        return a.compareTo(b);
    }
}));
