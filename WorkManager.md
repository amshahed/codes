# অ্যান্ড্রয়েডে ব্যাকগ্রাউন্ড টাস্কের জন্য WorkManager

আজকে আমরা **Android Jetpack**-এর একটি অত্যন্ত প্রয়োজনীয় এবং শক্তিশালী লাইব্রেরি নিয়ে জানব যার নাম হল **WorkManager**।

## WorkManager কি

WorkManager হচ্ছে **Android Jetpack** এর একটি কম্পোনেন্ট। যারা Android Jetpack কি এটা ভেবে মাথা চুলকানো শুরু করেছ, এটা হচ্ছে অ্যান্ড্রয়েড ডেভেলপমেন্টের জন্য **Google**-এর তৈরি নতুন সব কম্পোনেন্ট আর টুলস। এখানে নতুন অনেক দরকারি ফিচার যোগ করা হয়েছে এবং এমনভাবে ডিজাইন করা হয়েছে যেন কোন লাইব্রেরি ব্যবহার করতে কনফিগার করার জন্য অনেক বেশি কোড না লিখতে হয়। এসব বিভিন্ন দরকারি টুলস এর একটি হল WorkManager। এর মাধ্যমে বিভিন্ন শর্তসাপেক্ষে ব্যাকগ্রাউন্ড টাস্ক সম্পন্ন করা যায়।

## এত কিছু থাকতে WorkManager কেন

ব্যাকগ্রাউন্ড টাস্কের জন্য **JobScheduler**, **AlarmManager**, **FirebaseJobDispatcher** ইত্যাদি অনেক লাইব্রেরি অলরেডি আছে, তাহলে কষ্ট করে নতুন একটা কেন শিখতে যাবে? বেশ কিছু কারণ আছে।

- অন্যান্য লাইব্রেরিতে যেমন বয়লারপ্লেট কোড লিখতে লিখতে ঘাম ছুটে যায়, WorkManager-এ সেটা লাগে না। শুধুমাত্র কাজের কোডটুকু লিখলেই হল।
- কাজ দেয়ার পর অ্যাপ থেকে বের হয়ে গেলে বা ডিভাইস রিস্টার্ট করলেও কাজ হারিয়ে যাবে না।
- বিভিন্ন শর্তের ভিত্তিতে কাজ করানো যায়। যেমন, শুধুমাত্র ইন্টারনেট থাকলে কাজ করবে বা ডিভাইস চার্জে থাকা অবস্থায় কাজ করবে ইত্যাদি।
- ব্যাকগ্রাউন্ডে কাজ করলেও অ্যাপের সাথে তথ্য আদান-প্রদান করা যায়।
- একটি কাজ একবার অথবা একটি নির্দিষ্ট সময় পরপর করা যায়।
- কাজের চেইন তৈরি করা যায়, অর্থাৎ একটি কাজ শেষে আরেকটি শুরু হবে, এরপর আরেকটি। আবার একইসাথে একের বেশি কাজ করা যায়।
- অন্যান্য লাইব্রেরিতে ডিভাইস ভার্শন নিয়ে চিন্তা করতে হয়, একেক ভার্শনের জন্য একেক লাইব্রেরি নির্বাচন করতে হয়। এখানে তোমার এসব নিয়ে ভাবতে হবে না, ভার্শন অনুযায়ী সে নিজেই সঠিক প্রসেস নির্বাচন করে কাজ করবে।

বুঝতেই পারছ, খুবই কাজের একটি লাইব্রেরি এটা। কিন্তু একটা জিনিস মাথায় রাখতে হবে। কোন কাজ যদি একটি নির্দিষ্ট সময়ে করতে হয়, এর আগে বা পরে করলে হবে না এমন হয়, যেমন একটি নির্দিষ্ট সময় নোটিফিকেশন পাঠানো - তাহলে WorkManager দিয়ে কাজ হবে না। WorkManager নিশ্চিত করে যে কাজটি শর্ত অনুযায়ী হবেই, কিন্তু কোন সময়ে হবে তা তুমি নিয়ন্ত্রণ করতে পারবে না। তোমার কাজ যদি এমন হয় যে শর্ত মানতে হবে এবং করতেই হবে কিন্তু কোন সময় করবে সেটা ব্যাপার না, তাহলে WorkManager-ই তোমার জন্য সবচে ভাল লাইব্রেরি।

## কিছু রসকষহীন কিন্তু দরকারি তথ্য

WorkManager নিয়ে কাজ করতে কিছু ক্লাস ব্যবহার করতে হয়। তাই এই ক্লাসগুলো নিয়ে ধারণা থাকা জরুরি।

- ### Worker

    Worker মানেই হল যে কাজ করে। তুমি যে কাজ করতে চাও সেটা তাকে বুঝিয়ে দিলেই সময় হলে সে করে দিবে। এই ক্লাসটিকে *extend* করে এর `doWork()` মেথডটি ওভাররাইড করে বলে দিতে হবে আসলে কি কাজ করতে হবে।

- ### WorkRequest

    তুমি কাজটি কতবার করতে চাও এটা জানাই হচ্ছে এই ক্লাসের কাজ। এটি একটি ***abstract*** ক্লাস যার দুটো সাব-ক্লাস আছে। প্রথমটি হল `OneTimeWorkRequest`, এই ক্লাস ব্যবহার করব যখন আমরা কোন কাজ শুধুমাত্র একবার করতে চাই। দ্বিতীয়টি হল `PeriodicWorkRequest`, কোন কাজ বারবার করতে চাইলে এই ক্লাস ব্যবহার করব।

- ### WorkManager

    নাম থেকেই বোঝা যাচ্ছে সে ম্যানেজার। কোন কাজ কখন কিভাবে করতে হবে এগুলো দেখাশোনা করাই তার কাজ। সে একটি নিজস্ব ডাটাবেস বজায় রাখে যাতে অ্যাপ থেকে বের হয়ে গেলে বা ডিভাইস রিস্টার্ট করলেও কাজ হারিয়ে না যায়। আবার কাজটি করার জন্য JobScheduler, AlarmManager ইত্যাদির মধ্য থেকে কোন প্রসেসটি ব্যবহার করতে হবে তা ডিভাইস ভার্শন অনুযায়ী নিজেই ঠিক করে নেয়। এগুলো নিয়ে আমাদের চিন্তা করতে হবে না। আমরা Worker দিয়ে কাজটি ডিফাইন করে নির্দিষ্ট WorkRequest সিলেক্ট করে তাকে ধরিয়ে দিলে বা টেকনিকাল ভাষায় *enqueue* করে দিলেই আমাদের ম্যানেজার সব নিজেই ম্যানেজ করে নিবে।

- ### WorkInfo

    এই ক্লাসটির মধ্যে কাজ সম্পর্কে বিভিন্ন তথ্য থাকে, যেমন কাজটি সম্পন্ন হচ্ছে কিনা, সফল হয়েছে কিনা ইত্যাদি।

হয়ত এসব পড়ে খুব একটা কিছু বুঝতে পারনি, হয়ত ঠিকমত পড়ই নি। ভয় পাবার কিছু নেই। টেকনিকাল পোস্টে এসব বিবরণ কয়জনই বা পড়ে, একটু *scheme* করে কোডে চলে যায়। কোড দিয়ে উদাহরণ দিলে সব বুঝে যাবে।

## প্রথমে WorkManager যোগ করে নেই

আগেই বলেছি WorkManager হচ্ছে Android Jetpack-এর একটি কম্পোনেন্ট। Jetpack-এর কম্পোনেন্ট ব্যবহার করতে **AndroidX** লাইব্রেরি প্রয়োজন। AndroidX হচ্ছে বেসিক্যালি অ্যান্ড্রয়েডের **রিফ্রেশড** লাইব্রেরি যেখানে আগের সব ফিচার আরও ভালভাবে সাজানো হয়েছে এবং অনেক নতুন ফিচার যোগ করা হয়েছে। সুতরাং WorkManager ব্যবহার করতে হলে প্রজেক্টকে AndroidX সাপোর্ট করতে হবে।

### AndroidX সাপোর্ট করা প্রজেক্ট কিভাবে বানাবো

Android Studio-তে নতুন প্রজেক্ট শুরু করার সময় *Configure Your Project* অংশে নিচের নামে একটি চেকবক্স আছে।

>Use androidx.\* artifacts

এই বক্সকে চেক করলেই হল। উল্লেখ্য যে Android Studio-র ভার্শন **3.2** বা এর উপরে হতে হবে।

### আগের প্রজেক্টে কি AndroidX সাপোর্ট করা যাবে না

অবশ্যই যাবে, কিন্তু এর জন্য অ্যাপ লেভেল **build.gradle** ফাইলে গিয়ে দেখে নাও `compileSdkVersion` **28** বা এর উপরে কিনা, না থাকলে 28 করে নাও। এরপর উপরের মেনু থেকে নিচের কাজটি কর।

>Refactor > Migrate to AndroidX...

ব্যাস! পুরো প্রজেক্টকে AndroidX লাইব্রেরির ভেতরে নিয়ে আসা হবে। আবারও বলছি, এই চমৎকার ফিচারটি পেতে হলে Android Studio-র ভার্শন **3.2** বা এর উপরে হতে হবে। এর নিচে হলে একটু সময় নিয়ে আপডেট করে নাও।

AndroidX তো সাপোর্ট করা হল। এবার তো WorkManager যোগ করতে হবে। আবার প্রজেক্টের অ্যাপ লেভেল **build.gradle** ফাইলে *dependencies* অংশে নিচের লাইনটি যোগ করে প্রজেক্টটি *sync* করে নাও।

```gradle
implementation "androidx.work:work-runtime:2.2.0"
```

## এবার WorkManager দিয়ে একটা কাজ করি

জ্ঞান আহরণ এবং প্রজেক্ট সেট করার কাজ শেষ, এবার কাজের পালা। WorkManager দিয়ে বিভিন্ন কাজ করা যেতে পারে। যেমন, ইন্টারনেট আসলে অনলাইন রেজিস্ট্রেশনের কাজ সম্পন্ন করা, ডিভাইসের চার্জ বা স্টোরেজ কম হয়ে গেলে ইউজারকে জানানো, অ্যাপ থেকে রিমাইন্ডার দেয়া ইত্যাদি। আমরা একটা সোজাসাপটা কাজ করব WorkManager কিভাবে ব্যহার করতে হয় তা দেখার জন্য। অ্যাপ যখন নেটওয়ার্কে কানেক্ট করবে তখন আমরা একটি নোটিফিকেশন পাঠাবো।

প্রথমে নোটিফিকেশান পাঠানোর ফাংশনটা লিখে ফেলি। এই ফাংশন নোটিফিকেশনের টাইটেল এবং টেক্সট প্যারামিটার হিসেবে নিবে এবং একটি নোটিফিকেশন *build* করে **NotificationManager**-এর মাধ্যমে দেখাবে।

```java
private void sendNotification(String title, String text) {
    NotificationManager manager = (NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);
    String CHANNEL_ID = "work-manager-demo";
    String CHANNEL_NAME = "WorkManagerDemo";
    int NOTIFICATION_ID = 1;
    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
        NotificationChannel channel = new NotificationChannel(CHANNEL_ID, CHANNEL_NAME, NotificationManager.IMPORTANCE_DEFAULT);
        manager.createNotificationChannel(channel);
    }
    NotificationCompat.Builder builder = new NotificationCompat.Builder(context, CHANNEL_ID)
            .setContentTitle(title)
            .setContentText(text)
            .setSmallIcon(R.mipmap.ic_launcher);
    manager.notify(NOTIFICATION_ID, builder.build());
}
```

কাজটি করার জন্য একটি Worker লাগবে। আমরা **OneTimeWorker** নামে একটি ক্লাস তৈরি করলাম। এর `doWork()` মেথড ওভাররাইড করে আমরা `sendNotification()` ফাংশনটি কল করে দিলাম।

```java
@NonNull
@Override
public Result doWork() {
    Data data = getInputData();
    String title = data.getString(MainActivity.TITLE_KEY);
    String description = data.getString(MainActivity.TEXT_KEY);
    sendNotification(title, description);
    return Result.success();
}
```

এখানে এই লাইনটা নিয়ে কি চিন্তিত?

>Data data = getInputData();

চিন্তিত হবার কোন কারণ নেই। কোন নতুন Activity-তে যাওয়ার সময় যেমন আমরা Intent এর মধ্যে ডাটা পাঠাতে পারি, একইভাবে Worker-এর মধ্যেও পাঠানো যায়, যে ডাটা এই ফাংশন দিয়ে নিয়ে ব্যবহার করা যায়। এখানে আমরা নোটিফিকেশনের টাইটেল এবং টেক্সট পাঠিয়েছিলাম যা `data` ভ্যারিয়েবল থেকে নিচ্ছি। ডাটা কিভাবে পাঠাতে হয় সেটা একটু পরেই দেখাচ্ছি। আগে আমরা পুরো ক্লাসটি একবার দেখে নেই।

```java
public class OneTimeWork extends Worker {
    private Context context;

    public OneTimeWork(@NonNull Context context, @NonNull WorkerParameters workerParams) {
        super(context, workerParams);
        this.context = context;
    }

    @NonNull
    @Override
    public Result doWork() {
        Data data = getInputData();
        String title = data.getString(MainActivity.TITLE_KEY);
        String description = data.getString(MainActivity.TEXT_KEY);
        sendNotification(title, description);
        return Result.success();
    }

    private void sendNotification(String title, String text) {
        NotificationManager manager = (NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);
        String CHANNEL_ID = "work-manager-demo";
        String CHANNEL_NAME = "WorkManagerDemo";
        int NOTIFICATION_ID = 1;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            NotificationChannel channel = new NotificationChannel(CHANNEL_ID, CHANNEL_NAME, NotificationManager.IMPORTANCE_DEFAULT);
            manager.createNotificationChannel(channel);
        }
        NotificationCompat.Builder builder = new NotificationCompat.Builder(context, CHANNEL_ID)
                .setContentTitle(title)
                .setContentText(text)
                .setSmallIcon(R.mipmap.ic_launcher);
        manager.notify(NOTIFICATION_ID, builder.build());
    }
}
```

Worker-কে বুঝিয়ে দেয়া হল কি করতে হবে। এরপর আমরা একে ব্যবহার করব। এই কাজটা করা হবে **MainActivity**-তে। প্রথমে আমরা পাঠানোর জন্য ডাটা বানিয়ে নেই।

```java
public static final String TITLE_KEY = "title";
public static final String TEXT_KEY = "text";

Data data = new Data.Builder()
        .putString(TITLE_KEY, "One Time Work")
        .putString(TEXT_KEY, "Connected to internet!")
        .build();
```

আমরা বলেছি যে আমরা নোটিফিকেশন পাঠাব যখন নেটওয়ার্কে কানেক্ট করবে। মানে এটি হচ্ছে এই কাজের পূর্বশর্ত বা ***Constraint***। আমরা এবার এই শর্তটি সেট করব।

```java
Constraints constraints = new Constraints.Builder()
        .setRequiredNetworkType(NetworkType.CONNECTED)
        .build();
```

সব রেডি। আমরা যেহেতু কাজটি শুধু একবারই করব কাজেই OneTimeWorkRequest-এ কাজটিকে সেট করে WorkManager-এ *enqueue* করে দিব।

```java
final String UNIQUE_WORK_NAME = "one-time-work";
OneTimeWorkRequest oneTimeWorkRequest = new OneTimeWorkRequest
        .Builder(OneTimeWork.class)
        .setInputData(data)
        .setConstraints(constraints)
        .build();

WorkManager.getInstance(this).enqueueUniqueWork(
        UNIQUE_WORK_NAME,
        ExistingWorkPolicy.KEEP,
        oneTimeWorkRequest
);
```

ডিভাইসের নেটওয়ার্ক কানেক্ট না করে অ্যাপটি রান করলে দেখবে যে কোন নোটিফিকেশন আসছে না। কানেক্ট করা মাত্রই নোটিফিকেশন পাবে।

![One Time Work Notification](https://i.imgur.com/U4w6IZA.jpg?2)

WorkInfo-র মাধ্যমে আমরা কাজটির বিভিন্ন স্টেট জানতে পারি এবং সে অনুযায়ী UI আপডেট করতে পারি। এটি কিভাবে কাজ করে দেখানোর জন্য এই কাজটির WorkInfo-কে *observe* করে বিভিন্ন স্টেটগুলো TextView-তে দেখাচ্ছি।

```java
TextView info = findViewById(R.id.info);
WorkManager.getInstance(this).getWorkInfoByIdLiveData(oneTimeWorkRequest.getId())
        .observe(this, new Observer<WorkInfo>() {
            @Override
            public void onChanged(WorkInfo workInfo) {
                if (workInfo != null) {
                    info.append(workInfo.getState().name().concat("\n"));
                }
            }
        });
```

![One Time Work Info](https://i.imgur.com/xK6voX3.jpg?2)

এভাবেই যে কোন ব্যাকগ্রাউন্ড টাস্ক WorkManager দিয়ে করতে পারি।

## একই কাজ বারবার করতে চাইলে

কোন কাজ বারবার করতে চাইলে **PeriodicWorkRequest** ব্যবহার করতে হবে। যেমন নির্দিষ্ট সময় পরপর সার্ভারে ডাটা সিঙ্ক করতে চাইলে ইন্টারনেট কানেকশন লাগবে আবার ডিভাইসে চার্জ যেন থাকে তাও দেখতে হবে। এক্ষেত্রে এই লাইব্রেরি একদম মানানসই। এর জন্য আগের মত একইভাবে Worker ডিফাইন করে ডাটা এবং শর্ত যদি থাকে তা দিয়ে এরপর OneTimeWorkRequest ব্যবহার না করে PeriodicWorkRequest দিয়ে *enque* করতে হবে। পার্থক্য একটাই, এখানে বলে দিতে হবে কতক্ষণ পরপর কাজটি করতে হবে।

```java
final String PERIODIC_WORK_NAME = "periodic-work";
PeriodicWorkRequest periodicWorkRequest = new PeriodicWorkRequest
        .Builder(PeriodicWork.class, 15, TimeUnit.MINUTES)
        .build();
WorkManager.getInstance(this).enqueueUniquePeriodicWork(
        PERIODIC_WORK_NAME,
        ExistingPeriodicWorkPolicy.KEEP,
        periodicWorkRequest
);
```

![Periodic Work Notification](https://i.imgur.com/6UnmfDD.jpg?1)

এখানে একটা জিনিস মনে রাখা জরুরি যে বারবার করার ক্ষেত্রে সময়ের ব্যবধান কমপক্ষে **15 মিনিট** হতে হবে। অর্থাৎ, একবার কাজটি করার পর আবার করার আগে 15 মিনিট সময় পার হতে হবে। এই সময় নির্ধারণ করা হয়েছে ডিভাইসের ব্যাটারির কথা মাথায় রেখে। ব্যাকগ্রাউন্ডে একটি কাজ খুব দ্রুত বারবার চলতে থাকলে ব্যাটারি অনেক তাড়াতাড়ি ড্রেইন করে, যেটা কখনই ভাল ডিজাইন না। ইউজার যদি দেখে তোমার অ্যাপ ব্যবহার করতে গিয়ে তার ব্যাটারি বারবার অক্কা পাচ্ছে সে তোমার অ্যাপ ব্যবহার করাই ছেড়ে দিতে পারে। এরপরও এর চেয়ে কম সময়ের মধ্যে কাজ করতে চাইলে অন্য লাইব্রেরির সাহায্য নিতে হবে।

## শেষ কথা

পুরো কোডটি [ams-hasan/WorkManagerDemo](https://github.com/ams-hasan/WorkManagerDemo)-এই রিপোসিটরিতে আছে। আজকে আমরা WorkManager দেখলাম। আশা করি, নিজেদের অ্যাপের প্রয়োজনে সহজেই একে ব্যবহার করতে পারবে। আশা করি সামনে এমন আরও গুরুত্বপূর্ণ বিষয় নিয়ে কথা বলব। সে পর্যন্ত, হ্যাপি কোডিং!
