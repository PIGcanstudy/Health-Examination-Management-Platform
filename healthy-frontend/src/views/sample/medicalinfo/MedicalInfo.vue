<template>
  <medicalinfo :index="index" :arr="arr" />
</template>
<script>
import medicalinfo from '@/components/medicalinfo/MedicalInfo.vue'
export default {
  components: {
    medicalinfo
  },
  // 这里的数据可以由后端返回
  data() {
    return {
      // 显示当前是第几个流程
      index: 1,
      // 显示当前一共有哪些流程
      arr: ['登记', '在检', '总检', '已完成']
    }
  }
}
</script>
